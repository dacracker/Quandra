#! /usr/bin/env python3

import sys
sys.path.append(sys.path[0] + "/../../../")

from qpyapi import *

if __name__ == '__main__':
    if QApp_Init() != 0:
        sys.exit(0)

    window = QWindow('My Game', 800, 600)

    window.pump_events()

    window.destroy()

    QApp_Quit()
