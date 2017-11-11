#! /usr/bin/env python3

import sys
sys.path.append(sys.path[0] + "/../../../")

from qpyapi import *

if __name__ == '__main__':
    if qapp_init() != 0:
        sys.exit(1)

    qa_printf('Testing qa_printf! ÅÅÄÄÖÅ\n')

    qapp_quit()
