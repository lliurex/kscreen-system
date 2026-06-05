#!/usr/bin/env python3

import dbus


SERVICE_NAME = "net.lliurex.KScreenSystem"
OBJECT_PATH = "/net/lliurex/KScreenSystem"
INTERFACE = "net.lliurex.KScreenSystem"


def main():

    bus = dbus.SystemBus()

    proxy = bus.get_object(
        SERVICE_NAME,
        OBJECT_PATH
    )

    iface = dbus.Interface(
        proxy,
        INTERFACE
    )

    result = iface.SetGlobalConfigPath(
        "/home/user/.config/kscreen/config.json"
    )

    print("Result:", result)


if __name__ == "__main__":
    main()
