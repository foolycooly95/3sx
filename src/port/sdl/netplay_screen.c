#include "port/sdl/netplay_screen.h"
#include "netplay/fistbump.h"
#include "netplay/netplay.h"
#include "sf33rd/Source/Game/system/work_sys.h"
#include "sf33rd/Source/Game/ui/sc_sub.h"

#include <SDL3/SDL.h>

// Frames to hold the matchmaking message before switching to the next.
#define MM_TEXT_HOLD_FRAMES 30
// Frames to hold "Match found!" into the connecting phase before showing the game.
#define MATCH_FOUND_HOLD_FRAMES 90

static FistbumpConnectState display_state = FISTBUMP_CONN_IDLE;
static int transition_hold = 0;
static int match_found_hold = 0;

static const char* fb_conn_message(FistbumpConnectState s) {
    switch (s) {
    case FISTBUMP_CONN_RESOLVING_DNS:
    case FISTBUMP_CONN_CONNECTING_TCP:
        return "Connecting to server...";

    case FISTBUMP_CONN_ERROR:
        return "Matchmaking error";

    default:
        return "";
    }
}

static const char* fb_message(FistbumpState s) {
    static char out[256];

    switch (s) {
    case FISTBUMP_IDLE:
        return "";

    case FISTBUMP_CONNECTING:
    case FISTBUMP_AWAITING_ID:
        return "Connecting to server...";

    case FISTBUMP_SENDING_UDP:
        return "Sending UDP...";

    case FISTBUMP_LOGGING_IN:
    case FISTBUMP_AWAITING_LOGIN:
        DAG dag = Fistbump_GetDAG();

        SDL_snprintf(out, sizeof(out), "%s %s", dag.code, dag.activate_url);
        return out;

    case FISTBUMP_AWAITING_MATCH:
    case FISTBUMP_MATCHED:
    case FISTBUMP_ERROR:
        return "";

    default:
        return "";
    }
}

void NetplayScreen_Render() {
    const NetplaySessionState ns = Netplay_GetSessionState();
    const FistbumpConnectState fcs = Fistbump_GetConnectState();
    const FistbumpState mm = Fistbump_GetState();

    // While matchmaking is in progress show status text at the top of the
    // screen. This is safe at any time and doesn't require the full render pipeline.
    if (mm != FISTBUMP_IDLE && mm != FISTBUMP_MATCHED) {
        // Errors show immediately. Other state changes hold the current
        // message for MM_TEXT_HOLD_FRAMES before switching.
        if (fcs == FISTBUMP_CONN_ERROR) {
            display_state = fcs;
            transition_hold = 0;
        } else if (fcs == display_state) {
            // Do nothing
        } else if (transition_hold > 0) {
            transition_hold--;
        } else {
            display_state = fcs;
            transition_hold = MM_TEXT_HOLD_FRAMES;
        }

        if (fcs != FISTBUMP_CONN_CONNECTED) {
            SSPutStrPro(1, 384, 2, 9, 0xFFFFFFFF, fb_conn_message(display_state));
        } else {
            SSPutStrPro(1, 384, 2, 9, 0xFFFFFFFF, fb_message(mm));
        }
        return;
    }

    display_state = FISTBUMP_CONN_IDLE;
    transition_hold = 0;

    // After a match is found, show "Match found!" during VS mode loading and
    // hold it briefly into the connecting phase before revealing the game.
    // this should maybe be replaced by actual visual effects but good for a prototype.
    if (ns == NETPLAY_SESSION_TRANSITIONING) {
        match_found_hold = MATCH_FOUND_HOLD_FRAMES;
    } else if (match_found_hold > 0) {
        match_found_hold--;
    } else {
        return;
    }

    const char* msg = "Match found!";
    SSPutStrPro(1, 384, 110, 9, 0xFFFFFFFF, msg);
}
