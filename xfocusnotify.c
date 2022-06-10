#include <stdio.h>
#include <X11/Xatom.h>
#include <X11/Xlib.h>

int main() {
    Display *d = XOpenDisplay(NULL);
    if (!d) {
        printf("Couldn't open Display.\n");
        return 1;
    }
    const Atom net_active_window_atom = XInternAtom(d, "_NET_ACTIVE_WINDOW", False);
    const Window root = XDefaultRootWindow(d);
    XSelectInput(d, root, PropertyChangeMask);
    XEvent e;
    while (!XNextEvent(d, &e)) {
        if (e.xproperty.atom != net_active_window_atom)
            continue;
        unsigned long n;
        unsigned char *net_active_window;
        XGetWindowProperty(d, root, net_active_window_atom,
            0, sizeof(Window), False, XA_WINDOW, &(Atom) {0}, &(int) {0},
            &n, &(unsigned long) {0}, &net_active_window);
        if (n && net_active_window) {
            printf("0x%lx\n", *(Window *) net_active_window);
            XFree(net_active_window);
        }
        break;
    }
    XCloseDisplay(d);
}
