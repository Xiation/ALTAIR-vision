import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/abyan/Documents/FOR_ALTAIR/ALTAIR-vision/install/video_subscriber'
