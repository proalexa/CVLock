import cv2
import numpy as np
cap = cv2.VideoCapture(0)
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
gf=0
while True:
    ret, img = cap.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)
    for (x,y,w,h) in faces:
##        cv2.rectangle(img,(x,y),(x+w,y+h),(0,0,0),4)
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = img[y:y+h, x:x+w]
    cv2.imshow("frame",img)
    
    if cv2.waitKey(1) & 0xFF == ord('c'):
        gf+=1
        print("Blah")
        cv2.imwrite("MYFOLDER/Images/crop{}.jpg".format(gf),roi_color)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
