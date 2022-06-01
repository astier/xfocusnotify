## Description

[xfocusnotify](https://github.com/astier/xfocusnotify) is a X11-tool which exits
when a window is focused and prints the respective window-id. It's meant for
scripting where for some reason you need to know when a new window gets focused
and you want to do something with it. It follows
[EWMH](https://specifications.freedesktop.org/wm-spec/latest/)-specifications
and uses
[\_NET\_ACTIVE\_WINDOW](https://specifications.freedesktop.org/wm-spec/latest/ar01s03.html#idm45539547170400)
to determine the focused window.

## Installation

    sudo make install

## Example

The following shell-code prints the window-id each time a new window is focused:

    while window=$(xfocusnotify); do
        echo "focused $window"
    done

## Troubleshooting

If it doesn't report any focused windows it's probably because your
window-manager doesn't set \_NET\_ACTIVE\_WINDOW. Verify that it's set by
running:

    xprop -root

You should see the following line (the window-id might be different):

    _NET_ACTIVE_WINDOW(WINDOW): window id # 0xe00005

If you don't see it then \_NET\_ACTIVE\_WINDOW isn't set and you should ask the
developers of your window-manager to update it whenever a new window is focused.

## Similar programs

- [clipnotify](https://github.com/cdown/clipnotify)
