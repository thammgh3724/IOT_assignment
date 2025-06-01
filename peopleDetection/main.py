from ultralytics import YOLO
import cv2

# Load YOLOv8 model
model = YOLO(r'/Users/phongtran/Documents/dev/IOT_assignment/peopleDetection/best.pt')  # Path to your model

# Initialize the camera (0 is usually the default camera)
cap = cv2.VideoCapture(0)

# Check if the camera opened successfully
if not cap.isOpened():
    print("Error: Could not open camera.")
    exit()

while True:
    # Capture frame-by-frame
    ret, frame = cap.read()
    if not ret:
        print("Error: Failed to capture image.")
        break

    # Resize frame to 640x640 (as in your original code)
    frame = cv2.resize(frame, (640, 640))

    # Perform detection
    results = model(frame)
    annotated_frame = results[0].plot()  # Draw bounding boxes and labels

    # Display the frame with detections
    cv2.imshow("YOLOv8 Detection", annotated_frame)

    # Break the loop if 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the camera and close windows
cap.release()
cv2.destroyAllWindows()