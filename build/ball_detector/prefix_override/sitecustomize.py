import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/lexciese/Dev/temp/ALTAIR-vision/install/ball_detector'
