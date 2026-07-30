#define ONESHOT_TAP_TOGGLE 10  /* Tapping this number of times holds the key until tapped once again. */
// #define TAPPING_TERM 200
// HOLD_ON_OTHER_KEY_PRESS

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define QUICK_TAP_TERM 0

// TAP-HOLD SETTINGS
// #define TAPPING_TERM 175
// #define PERMISSIVE_HOLD

// TAP-HOLD SETTINGS FOR HOME ROW MODS
#define CHORDAL_HOLD        // only activate hold when next key is opposite hand
#define FLOW_TAP_TERM 150   // force tap if you were typing within 150ms

// for home row mods:
// #define TAPPING_TERM 220    // up from 175 — more room to intentionally hold

// without home row mods:
#define TAPPING_TERM 175    // up from 175 — more room to intentionally hold


#define COMBO_TERM 40


#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Enable the `combo_should_trigger` function so I can disable combos on the
// gaming layer
#define COMBO_SHOULD_TRIGGER
