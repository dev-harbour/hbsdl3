#ifndef SDL_VIDEO_CH_
#define SDL_VIDEO_CH_

#define SDL_PROP_GLOBAL_VIDEO_WAYLAND_WL_DISPLAY_POINTER "SDL.video.wayland.wl_display"

#define SDL_SYSTEM_THEME_UNKNOWN              0
#define SDL_SYSTEM_THEME_LIGHT                1
#define SDL_SYSTEM_THEME_DARK                 2

#define SDL_ORIENTATION_UNKNOWN               0
#define SDL_ORIENTATION_LANDSCAPE             1
#define SDL_ORIENTATION_LANDSCAPE_FLIPPED     2
#define SDL_ORIENTATION_PORTRAIT              3
#define SDL_ORIENTATION_PORTRAIT_FLIPPED      4

#define SDL_WINDOW_FULLSCREEN                 SDL_UINT64_C(0x0000000000000001)
#define SDL_WINDOW_OPENGL                     SDL_UINT64_C(0x0000000000000002)
#define SDL_WINDOW_OCCLUDED                   SDL_UINT64_C(0x0000000000000004)
#define SDL_WINDOW_HIDDEN                     SDL_UINT64_C(0x0000000000000008)
#define SDL_WINDOW_BORDERLESS                 SDL_UINT64_C(0x0000000000000010)
#define SDL_WINDOW_RESIZABLE                  SDL_UINT64_C(0x0000000000000020)
#define SDL_WINDOW_MINIMIZED                  SDL_UINT64_C(0x0000000000000040)
#define SDL_WINDOW_MAXIMIZED                  SDL_UINT64_C(0x0000000000000080)
#define SDL_WINDOW_MOUSE_GRABBED              SDL_UINT64_C(0x0000000000000100)
#define SDL_WINDOW_INPUT_FOCUS                SDL_UINT64_C(0x0000000000000200)
#define SDL_WINDOW_MOUSE_FOCUS                SDL_UINT64_C(0x0000000000000400)
#define SDL_WINDOW_EXTERNAL                   SDL_UINT64_C(0x0000000000000800)
#define SDL_WINDOW_MODAL                      SDL_UINT64_C(0x0000000000001000)
#define SDL_WINDOW_HIGH_PIXEL_DENSITY         SDL_UINT64_C(0x0000000000002000)
#define SDL_WINDOW_MOUSE_CAPTURE              SDL_UINT64_C(0x0000000000004000)
#define SDL_WINDOW_MOUSE_RELATIVE_MODE        SDL_UINT64_C(0x0000000000008000)
#define SDL_WINDOW_ALWAYS_ON_TOP              SDL_UINT64_C(0x0000000000010000)
#define SDL_WINDOW_UTILITY                    SDL_UINT64_C(0x0000000000020000)
#define SDL_WINDOW_TOOLTIP                    SDL_UINT64_C(0x0000000000040000)
#define SDL_WINDOW_POPUP_MENU                 SDL_UINT64_C(0x0000000000080000)
#define SDL_WINDOW_KEYBOARD_GRABBED           SDL_UINT64_C(0x0000000000100000)
#define SDL_WINDOW_VULKAN                     SDL_UINT64_C(0x0000000010000000)
#define SDL_WINDOW_METAL                      SDL_UINT64_C(0x0000000020000000)
#define SDL_WINDOW_TRANSPARENT                SDL_UINT64_C(0x0000000040000000)
#define SDL_WINDOW_NOT_FOCUSABLE              SDL_UINT64_C(0x0000000080000000)

#define SDL_WINDOWPOS_UNDEFINED_MASK          0x1FFF0000
#define SDL_WINDOWPOS_UNDEFINED_DISPLAY(X)    hb_BitOr(SDL_WINDOWPOS_UNDEFINED_MASK,(X))
#define SDL_WINDOWPOS_UNDEFINED               SDL_WINDOWPOS_UNDEFINED_DISPLAY(0)
#define SDL_WINDOWPOS_ISUNDEFINED(X)          (hb_BitAnd((X),0xFFFF0000) == SDL_WINDOWPOS_UNDEFINED_MASK)

#define SDL_WINDOWPOS_CENTERED_MASK           0x2FFF0000
#define SDL_WINDOWPOS_CENTERED_DISPLAY(X)     hb_BitOr(SDL_WINDOWPOS_CENTERED_MASK,(X))
#define SDL_WINDOWPOS_CENTERED                SDL_WINDOWPOS_CENTERED_DISPLAY(0)
#define SDL_WINDOWPOS_ISCENTERED(X)           (hb_BitAnd((X),0xFFFF0000) == SDL_WINDOWPOS_CENTERED_MASK)

#define SDL_FLASH_CANCEL                       0
#define SDL_FLASH_BRIEFLY                      1
#define SDL_FLASH_UNTIL_FOCUSED                2

#define  SDL_GL_RED_SIZE                       0
#define  SDL_GL_GREEN_SIZE                     1
#define  SDL_GL_BLUE_SIZE                      2
#define  SDL_GL_ALPHA_SIZE                     3
#define  SDL_GL_BUFFER_SIZE                    4
#define  SDL_GL_DOUBLEBUFFER                   5
#define  SDL_GL_DEPTH_SIZE                     6
#define  SDL_GL_STENCIL_SIZE                   7
#define  SDL_GL_ACCUM_RED_SIZE                 8
#define  SDL_GL_ACCUM_GREEN_SIZE               9
#define  SDL_GL_ACCUM_BLUE_SIZE                10
#define  SDL_GL_ACCUM_ALPHA_SIZE               11
#define  SDL_GL_STEREO                         12
#define  SDL_GL_MULTISAMPLEBUFFERS             13
#define  SDL_GL_MULTISAMPLESAMPLES             14
#define  SDL_GL_ACCELERATED_VISUAL             15
#define  SDL_GL_RETAINED_BACKING               16
#define  SDL_GL_CONTEXT_MAJOR_VERSION          17
#define  SDL_GL_CONTEXT_MINOR_VERSION          18
#define  SDL_GL_CONTEXT_FLAGS                  19
#define  SDL_GL_CONTEXT_PROFILE_MASK           20
#define  SDL_GL_SHARE_WITH_CURRENT_CONTEXT     21
#define  SDL_GL_FRAMEBUFFER_SRGB_CAPABLE       22
#define  SDL_GL_CONTEXT_RELEASE_BEHAVIOR       23
#define  SDL_GL_CONTEXT_RESET_NOTIFICATION     24
#define  SDL_GL_CONTEXT_NO_ERROR               25
#define  SDL_GL_FLOATBUFFERS                   26
#define  SDL_GL_EGL_PLATFORM                   27

#define SDL_GL_CONTEXT_PROFILE_CORE            0x0001
#define SDL_GL_CONTEXT_PROFILE_COMPATIBILITY   0x0002
#define SDL_GL_CONTEXT_PROFILE_ES              0x0004

#define SDL_GL_CONTEXT_DEBUG_FLAG              0x0001
#define SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG 0x0002
#define SDL_GL_CONTEXT_ROBUST_ACCESS_FLAG      0x0004
#define SDL_GL_CONTEXT_RESET_ISOLATION_FLAG    0x0008

#define SDL_GL_CONTEXT_RELEASE_BEHAVIOR_NONE   0x0000
#define SDL_GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH  0x0001

#define SDL_GL_CONTEXT_RESET_NO_NOTIFICATION   0x0000
#define SDL_GL_CONTEXT_RESET_LOSE_CONTEXT      0x0001

#define SDL_PROP_DISPLAY_HDR_ENABLED_BOOLEAN                       "SDL.display.HDR_enabled"
#define SDL_PROP_DISPLAY_KMSDRM_PANEL_ORIENTATION_NUMBER           "SDL.display.KMSDRM.panel_orientation"

#define SDL_PROP_WINDOW_CREATE_ALWAYS_ON_TOP_BOOLEAN               "SDL.window.create.always_on_top"
#define SDL_PROP_WINDOW_CREATE_BORDERLESS_BOOLEAN                  "SDL.window.create.borderless"
#define SDL_PROP_WINDOW_CREATE_FOCUSABLE_BOOLEAN                   "SDL.window.create.focusable"
#define SDL_PROP_WINDOW_CREATE_EXTERNAL_GRAPHICS_CONTEXT_BOOLEAN   "SDL.window.create.external_graphics_context"
#define SDL_PROP_WINDOW_CREATE_FLAGS_NUMBER                        "SDL.window.create.flags"
#define SDL_PROP_WINDOW_CREATE_FULLSCREEN_BOOLEAN                  "SDL.window.create.fullscreen"
#define SDL_PROP_WINDOW_CREATE_HEIGHT_NUMBER                       "SDL.window.create.height"
#define SDL_PROP_WINDOW_CREATE_HIDDEN_BOOLEAN                      "SDL.window.create.hidden"
#define SDL_PROP_WINDOW_CREATE_HIGH_PIXEL_DENSITY_BOOLEAN          "SDL.window.create.high_pixel_density"
#define SDL_PROP_WINDOW_CREATE_MAXIMIZED_BOOLEAN                   "SDL.window.create.maximized"
#define SDL_PROP_WINDOW_CREATE_MENU_BOOLEAN                        "SDL.window.create.menu"
#define SDL_PROP_WINDOW_CREATE_METAL_BOOLEAN                       "SDL.window.create.metal"
#define SDL_PROP_WINDOW_CREATE_MINIMIZED_BOOLEAN                   "SDL.window.create.minimized"
#define SDL_PROP_WINDOW_CREATE_MODAL_BOOLEAN                       "SDL.window.create.modal"
#define SDL_PROP_WINDOW_CREATE_MOUSE_GRABBED_BOOLEAN               "SDL.window.create.mouse_grabbed"
#define SDL_PROP_WINDOW_CREATE_OPENGL_BOOLEAN                      "SDL.window.create.opengl"
#define SDL_PROP_WINDOW_CREATE_PARENT_POINTER                      "SDL.window.create.parent"
#define SDL_PROP_WINDOW_CREATE_RESIZABLE_BOOLEAN                   "SDL.window.create.resizable"
#define SDL_PROP_WINDOW_CREATE_TITLE_STRING                        "SDL.window.create.title"
#define SDL_PROP_WINDOW_CREATE_TRANSPARENT_BOOLEAN                 "SDL.window.create.transparent"
#define SDL_PROP_WINDOW_CREATE_TOOLTIP_BOOLEAN                     "SDL.window.create.tooltip"
#define SDL_PROP_WINDOW_CREATE_UTILITY_BOOLEAN                     "SDL.window.create.utility"
#define SDL_PROP_WINDOW_CREATE_VULKAN_BOOLEAN                      "SDL.window.create.vulkan"
#define SDL_PROP_WINDOW_CREATE_WIDTH_NUMBER                        "SDL.window.create.width"
#define SDL_PROP_WINDOW_CREATE_X_NUMBER                            "SDL.window.create.x"
#define SDL_PROP_WINDOW_CREATE_Y_NUMBER                            "SDL.window.create.y"
#define SDL_PROP_WINDOW_CREATE_COCOA_WINDOW_POINTER                "SDL.window.create.cocoa.window"
#define SDL_PROP_WINDOW_CREATE_COCOA_VIEW_POINTER                  "SDL.window.create.cocoa.view"
#define SDL_PROP_WINDOW_CREATE_WAYLAND_SURFACE_ROLE_CUSTOM_BOOLEAN "SDL.window.create.wayland.surface_role_custom"
#define SDL_PROP_WINDOW_CREATE_WAYLAND_CREATE_EGL_WINDOW_BOOLEAN   "SDL.window.create.wayland.create_egl_window"
#define SDL_PROP_WINDOW_CREATE_WAYLAND_WL_SURFACE_POINTER          "SDL.window.create.wayland.wl_surface"
#define SDL_PROP_WINDOW_CREATE_WIN32_HWND_POINTER                  "SDL.window.create.win32.hwnd"
#define SDL_PROP_WINDOW_CREATE_WIN32_PIXEL_FORMAT_HWND_POINTER     "SDL.window.create.win32.pixel_format_hwnd"
#define SDL_PROP_WINDOW_CREATE_X11_WINDOW_NUMBER                   "SDL.window.create.x11.window"

#define SDL_PROP_WINDOW_SHAPE_POINTER                              "SDL.window.shape"
#define SDL_PROP_WINDOW_HDR_ENABLED_BOOLEAN                        "SDL.window.HDR_enabled"
#define SDL_PROP_WINDOW_SDR_WHITE_LEVEL_FLOAT                      "SDL.window.SDR_white_level"
#define SDL_PROP_WINDOW_HDR_HEADROOM_FLOAT                         "SDL.window.HDR_headroom"
#define SDL_PROP_WINDOW_ANDROID_WINDOW_POINTER                     "SDL.window.android.window"
#define SDL_PROP_WINDOW_ANDROID_SURFACE_POINTER                    "SDL.window.android.surface"
#define SDL_PROP_WINDOW_UIKIT_WINDOW_POINTER                       "SDL.window.uikit.window"
#define SDL_PROP_WINDOW_UIKIT_METAL_VIEW_TAG_NUMBER                "SDL.window.uikit.metal_view_tag"
#define SDL_PROP_WINDOW_UIKIT_OPENGL_FRAMEBUFFER_NUMBER            "SDL.window.uikit.opengl.framebuffer"
#define SDL_PROP_WINDOW_UIKIT_OPENGL_RENDERBUFFER_NUMBER           "SDL.window.uikit.opengl.renderbuffer"
#define SDL_PROP_WINDOW_UIKIT_OPENGL_RESOLVE_FRAMEBUFFER_NUMBER    "SDL.window.uikit.opengl.resolve_framebuffer"
#define SDL_PROP_WINDOW_KMSDRM_DEVICE_INDEX_NUMBER                 "SDL.window.kmsdrm.dev_index"
#define SDL_PROP_WINDOW_KMSDRM_DRM_FD_NUMBER                       "SDL.window.kmsdrm.drm_fd"
#define SDL_PROP_WINDOW_KMSDRM_GBM_DEVICE_POINTER                  "SDL.window.kmsdrm.gbm_dev"
#define SDL_PROP_WINDOW_COCOA_WINDOW_POINTER                       "SDL.window.cocoa.window"
#define SDL_PROP_WINDOW_COCOA_METAL_VIEW_TAG_NUMBER                "SDL.window.cocoa.metal_view_tag"
#define SDL_PROP_WINDOW_OPENVR_OVERLAY_ID                          "SDL.window.openvr.overlay_id"
#define SDL_PROP_WINDOW_VIVANTE_DISPLAY_POINTER                    "SDL.window.vivante.display"
#define SDL_PROP_WINDOW_VIVANTE_WINDOW_POINTER                     "SDL.window.vivante.window"
#define SDL_PROP_WINDOW_VIVANTE_SURFACE_POINTER                    "SDL.window.vivante.surface"
#define SDL_PROP_WINDOW_WIN32_HWND_POINTER                         "SDL.window.win32.hwnd"
#define SDL_PROP_WINDOW_WIN32_HDC_POINTER                          "SDL.window.win32.hdc"
#define SDL_PROP_WINDOW_WIN32_INSTANCE_POINTER                     "SDL.window.win32.instance"
#define SDL_PROP_WINDOW_WAYLAND_DISPLAY_POINTER                    "SDL.window.wayland.display"
#define SDL_PROP_WINDOW_WAYLAND_SURFACE_POINTER                    "SDL.window.wayland.surface"
#define SDL_PROP_WINDOW_WAYLAND_VIEWPORT_POINTER                   "SDL.window.wayland.viewport"
#define SDL_PROP_WINDOW_WAYLAND_EGL_WINDOW_POINTER                 "SDL.window.wayland.egl_window"
#define SDL_PROP_WINDOW_WAYLAND_XDG_SURFACE_POINTER                "SDL.window.wayland.xdg_surface"
#define SDL_PROP_WINDOW_WAYLAND_XDG_TOPLEVEL_POINTER               "SDL.window.wayland.xdg_toplevel"
#define SDL_PROP_WINDOW_WAYLAND_XDG_TOPLEVEL_EXPORT_HANDLE_STRING  "SDL.window.wayland.xdg_toplevel_export_handle"
#define SDL_PROP_WINDOW_WAYLAND_XDG_POPUP_POINTER                  "SDL.window.wayland.xdg_popup"
#define SDL_PROP_WINDOW_WAYLAND_XDG_POSITIONER_POINTER             "SDL.window.wayland.xdg_positioner"
#define SDL_PROP_WINDOW_X11_DISPLAY_POINTER                        "SDL.window.x11.display"
#define SDL_PROP_WINDOW_X11_SCREEN_NUMBER                          "SDL.window.x11.screen"
#define SDL_PROP_WINDOW_X11_WINDOW_NUMBER                          "SDL.window.x11.window"

#define SDL_WINDOW_SURFACE_VSYNC_DISABLED                            0
#define SDL_WINDOW_SURFACE_VSYNC_ADAPTIVE                          (-1)

#define SDL_HITTEST_NORMAL                                           0
#define SDL_HITTEST_DRAGGABLE                                        1
#define SDL_HITTEST_RESIZE_TOPLEFT                                   2
#define SDL_HITTEST_RESIZE_TOP                                       3
#define SDL_HITTEST_RESIZE_TOPRIGHT                                  4
#define SDL_HITTEST_RESIZE_RIGHT                                     5
#define SDL_HITTEST_RESIZE_BOTTOMRIGHT                               6
#define SDL_HITTEST_RESIZE_BOTTOM                                    7
#define SDL_HITTEST_RESIZE_BOTTOMLEFT                                8
#define SDL_HITTEST_RESIZE_LEFT                                      9

#endif /* END SDL_VIDEO_CH_ */
