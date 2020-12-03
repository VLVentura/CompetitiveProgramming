#!/usr/bin/env python3.8
import sys

from scripts.mainscript import Script

if __name__ == '__main__':
    args = sys.argv
    script = Script(args)
    script.run()
