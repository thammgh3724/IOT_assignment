from ultralytics import YOLO
import cv2

# Load YOLOv8 model
model = YOLO(r'peopleDetection\best.pt')  # hoặc đường dẫn tới file yolov8n.pt của bạn

# Load image
image_path = r'peopleDetection\test_picture.jpg'  # thay bằng đường dẫn ảnh của bạn
image = cv2.imread(image_path)
image = cv2.resize(image, (640, 640))

#Predict
results = model(image)
annotated_image = results[0].plot()

# Show result
cv2.imshow("Detected Image", annotated_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
