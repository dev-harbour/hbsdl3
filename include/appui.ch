#ifndef APPUI_CH_
#define APPUI_CH_

#define BLACK         { 0x0C, 0x0C, 0x0C, 0xFF }
#define BLUE          { 0x00, 0x37, 0xDA, 0xFF }
#define GREEN         { 0x13, 0xA1, 0x0E, 0xFF }
#define CYAN          { 0x3A, 0x96, 0xDD, 0xFF }
#define RED           { 0xC5, 0x0F, 0x1F, 0xFF }
#define MAGENTA       { 0x88, 0x17, 0x98, 0xFF }
#define BROWN         { 0xC1, 0x9C, 0x00, 0xFF }
#define LIGHT_GRAY    { 0xCC, 0xCC, 0xCC, 0xFF }
#define GRAY          { 0x76, 0x76, 0x76, 0xFF }
#define LIGHT_BLUE    { 0x3B, 0x78, 0xFF, 0xFF }
#define LIGHT_GREEN   { 0x16, 0xC6, 0x0C, 0xFF }
#define LIGHT_CYAN    { 0x61, 0xD6, 0xD6, 0xFF }
#define LIGHT_RED     { 0xE7, 0x48, 0x56, 0xFF }
#define LIGHT_MAGENTA { 0xB4, 0x00, 0x9E, 0xFF }
#define YELLOW        { 0xF9, 0xF1, 0xA5, 0xFF }
#define WHITE         { 0xF2, 0xF2, 0xF2, 0xFF }

#define WINDOW_FULLSCREEN           0x0000000000000001   /**< window is in fullscreen mode */
#define WINDOW_OPENGL               0x0000000000000002   /**< window usable with OpenGL context */
#define WINDOW_OCCLUDED             0x0000000000000004   /**< window is occluded */
#define WINDOW_HIDDEN               0x0000000000000008   /**< window is neither mapped onto the desktop nor shown in the taskbar/dock/window list; SDL_ShowWindow() is required for it to become visible */
#define WINDOW_BORDERLESS           0x0000000000000010   /**< no window decoration */
#define WINDOW_RESIZABLE            0x0000000000000020   /**< window can be resized */
#define WINDOW_MINIMIZED            0x0000000000000040   /**< window is minimized */
#define WINDOW_MAXIMIZED            0x0000000000000080   /**< window is maximized */
#define WINDOW_MOUSE_GRABBED        0x0000000000000100   /**< window has grabbed mouse input */
#define WINDOW_INPUT_FOCUS          0x0000000000000200   /**< window has input focus */
#define WINDOW_MOUSE_FOCUS          0x0000000000000400   /**< window has mouse focus */
#define WINDOW_EXTERNAL             0x0000000000000800   /**< window not created by SDL */
#define WINDOW_MODAL                0x0000000000001000   /**< window is modal */
#define WINDOW_HIGH_PIXEL_DENSITY   0x0000000000002000   /**< window uses high pixel density back buffer if possible */
#define WINDOW_MOUSE_CAPTURE        0x0000000000004000   /**< window has mouse captured (unrelated to MOUSE_GRABBED) */
#define WINDOW_MOUSE_RELATIVE_MODE  0x0000000000008000   /**< window has relative mode enabled */
#define WINDOW_ALWAYS_ON_TOP        0x0000000000010000   /**< window should always be above others */
#define WINDOW_UTILITY              0x0000000000020000   /**< window should be treated as a utility window, not showing in the task bar and window list */
#define WINDOW_TOOLTIP              0x0000000000040000   /**< window should be treated as a tooltip and does not get mouse or keyboard focus, requires a parent window */
#define WINDOW_POPUP_MENU           0x0000000000080000   /**< window should be treated as a popup menu, requires a parent window */
#define WINDOW_KEYBOARD_GRABBED     0x0000000000100000   /**< window has grabbed keyboard input */
#define WINDOW_VULKAN               0x0000000010000000   /**< window usable for Vulkan surface */
#define WINDOW_METAL                0x0000000020000000   /**< window usable for Metal view */
#define WINDOW_TRANSPARENT          0x0000000040000000   /**< window with transparent buffer */
#define WINDOW_NOT_FOCUSABLE        0x0000000080000000   /**< window should not be focusable */

#endif /* End APPUI_CH_ */
