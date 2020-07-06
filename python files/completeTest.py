import socket
from time import sleep
import datetime
import cv2
import math

arduino = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
arduino.connect(('192.168.0.179', 80))

#current position of the motors bound by 200 (200 steps per motor)
xMotor = 50     #starts in the middle
yMotor = 0
verticalMove = False
horizontalMove = False
moveTimeV = 0
moveTimeH = 0

INTERVAL_TIME_VERTICAL = .2   #time between motor movements
INTERVAL_TIME_HORIZONTAL = .90

def main():
    run()

    
def run():
    global verticalMove
    global horizontalMove
    global moveTimeV
    global moveTimeH
    global INTERVAL_TIME_VERTICAL
    global INTERVAL_TIME_HORIZONTAL

    faceCascade = cv2.CascadeClassifier('face.xml')
    video_capture = cv2.VideoCapture(0)

    while True:
        # Capture frame-by-frame
        ret, frame = video_capture.read()

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        faces = faceCascade.detectMultiScale(
            gray,
            scaleFactor=1.1,
            minNeighbors=5,
            minSize=(30, 30),
            flags=cv2.CASCADE_SCALE_IMAGE
        )


        # Draw a rectangle around the faces
        for (x, y, w, h) in faces:
            cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)

        # Display the resulting frame
        cv2.imshow('Video', frame)

        if verticalMove:
            if((datetime.datetime.utcnow().timestamp() - moveTimeV) >= INTERVAL_TIME_VERTICAL):
                verticalMove = False

        if horizontalMove:
            if((datetime.datetime.utcnow().timestamp() - moveTimeH) >= INTERVAL_TIME_HORIZONTAL):
                horizontalMove = False

        # if there is 1 face in the frame
        if len(faces) == 1:
            print(str(x + w/2) + " , " + str(y + y/2), end="\r")
            #these are the coordinates 
            if not verticalMove:
                verticalMove = True
                moveTimeV = int(datetime.datetime.utcnow().timestamp())
                calcDistanceVertical((y + y/2))
            if not horizontalMove:
                horizontalMove = True
                moveTimeH = int(datetime.datetime.utcnow().timestamp())
                calcDistanceHorizontal((x + w/2))

        if cv2.waitKey(1) & 0xFF == ord('q'):
            sendSignal('u',yMotor) #reset motor
            break


    # When everything is done, release the capture
    print()
    video_capture.release()
    cv2.destroyAllWindows()


def calcDistanceVertical(yPos):
    global yMotor
    
    distanceFromTop = yPos / 50
    if(distanceFromTop % 1 >= .50):
        distanceFromTop = math.ceil(distanceFromTop)
    else:
        distanceFromTop = math.floor(distanceFromTop)
    distance = abs(yMotor - 37 - distanceFromTop)

    if(distance > 1):
        if((yMotor - 37) > distanceFromTop):
            sendSignal('u',distance)
        else:
            sendSignal('d',distance)


def calcDistanceHorizontal(xPos):
    global xMotor

    if(xPos < 305):
        distanceFromCentre = (350 - xPos) / 50

        if(distanceFromCentre % 1 >= .50):
            distanceFromCentre = math.ceil(distanceFromCentre)
        else:
            distanceFromCentre = math.floor(distanceFromCentre)

        sendSignal('l',distanceFromCentre)

    elif(xPos > 395):
        distanceFromCentre = (xPos - 350) / 50

        if(distanceFromCentre % 1 >= .50):
            distanceFromCentre = math.ceil(distanceFromCentre)
        else:
            distanceFromCentre = math.floor(distanceFromCentre)

        sendSignal('r',distanceFromCentre)




def sendSignal(direction,distance):
    global yMotor
    global xMotor
    my_bytes = bytearray()

    my_bytes.append(ord(direction))
    my_bytes.append(int(distance))

    arduino.sendall(my_bytes)
    if(direction == 'd'):
        yMotor = (yMotor + distance) % 200
    elif (direction == 'u'):
        yMotor = (yMotor - distance) % 200
    elif (direction == 'l'):
        xMotor = (xMotor - distance) % 200
    elif (direction == 'r'):
        xMotor = (xMotor + distance) % 200


main()
print()
#delay before exiting
sleep(.5)
#arduino.shutdown()
#arduino.close()