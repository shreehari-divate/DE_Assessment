import cv2
import os

data = cv2.imread(r'G:\shree\New folder\python\PY_CV\CVP\DE\G178_2 -1080.BMP')
size=(1920,1080)
#Inter_linear
linear = cv2.resize(src=data,dsize=None, fx=0.5, fy=0.5, interpolation=cv2.INTER_LINEAR)
#Inter_nearest
nearest = cv2.resize(src=data, dsize=None, fx=0.5,fy=0.5, interpolation=cv2.INTER_NEAREST)
#Inter_cubic
cubic = cv2.resize(src=data, dsize=None, fx=0.5,fy=0.5, interpolation=cv2.INTER_CUBIC)

cv2.imshow('Original',data)
cv2.imshow('Inter_linear',linear)
cv2.imshow('Inter_nearest',nearest)
cv2.imshow('Inter_cubic',cubic)

cv2.waitKey(0)
cv2.destroyAllWindows()

