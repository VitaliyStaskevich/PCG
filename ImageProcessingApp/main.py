import cv2
from PySide6.QtCore import Qt, QTimer
from PySide6.QtGui import QImage, QPixmap
from PySide6.QtWidgets import (
    QApplication,
    QLabel,
    QMainWindow,
    QVBoxLayout,
    QWidget,
    QPushButton,
    QFileDialog,
)
import numpy as np
from skimage.morphology import skeletonize

class ImageProcessingApp(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Image Processing App")

        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)

        self.image_label = QLabel()
        self.image_label.setAlignment(Qt.AlignCenter)

        self.layout = QVBoxLayout(self.central_widget)
        self.layout.addWidget(self.image_label)

        self.load_image_button = QPushButton("Выбрать изображение")
        self.layout.addWidget(self.load_image_button)
        self.load_image_button.clicked.connect(self.load_image_dialog)

        self.erode_button = QPushButton("Выполнить эрозию")
        self.layout.addWidget(self.erode_button)
        self.erode_button.clicked.connect(self.process_erode)

        self.smooth_button = QPushButton("Применить сглаживающий фильтр")
        self.layout.addWidget(self.smooth_button)
        self.smooth_button.clicked.connect(self.process_smooth)

        self.dilate_button = QPushButton("Выполнить дилатацию")
        self.layout.addWidget(self.dilate_button)
        self.dilate_button.clicked.connect(self.process_dilate)

        self.skeletonize_button = QPushButton("Скелетонизация")
        self.layout.addWidget(self.skeletonize_button)
        self.skeletonize_button.clicked.connect(self.process_skeletonize)

        self.image_path = None
        self.current_image = None

    def load_image_dialog(self):
        options = QFileDialog.Options()
        options |= QFileDialog.ReadOnly

        file_dialog = QFileDialog()
        file_dialog.setFileMode(QFileDialog.ExistingFile)
        file_dialog.setNameFilter("Images (*.png *.jpg *.bmp)")
        file_dialog.setViewMode(QFileDialog.Detail)
        file_dialog.setOptions(options)

        if file_dialog.exec():
            selected_file = file_dialog.selectedFiles()[0]
            self.image_path = selected_file
            self.load_image()

    def load_image(self):
        image = cv2.imread(self.image_path)
        self.current_image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        self.display_image()

    def display_image(self):
        height, width, channel = self.current_image.shape
        bytes_per_line = 3 * width
        q_image = QImage(self.current_image.data, width, height, bytes_per_line, QImage.Format_RGB888)
        pixmap = QPixmap.fromImage(q_image)
        self.image_label.setPixmap(pixmap)

    def process_erode(self):
        if self.current_image is not None:
            kernel = np.ones((5, 5), np.uint8)
            eroded_image = cv2.erode(self.current_image, kernel, iterations=1)
            self.current_image = eroded_image
            self.display_image()

    def process_smooth(self):
        if self.current_image is not None:
            smoothed_image = cv2.GaussianBlur(self.current_image, (5, 5), 0)
            self.current_image = smoothed_image
            self.display_image()
    def process_dilate(self):
        if self.current_image is not None:
            kernel = np.ones((5, 5), np.uint8)
            dilated_image = cv2.dilate(self.current_image, kernel, iterations=1)
            self.current_image = dilated_image
            self.display_image()

    def process_skeletonize(self):
        if self.current_image is not None:
            gray_image = cv2.cvtColor(self.current_image, cv2.COLOR_RGB2GRAY)
            thin_image = skeletonize(gray_image > 0)
            thin_image = thin_image.astype(np.uint8) * 255
            self.current_image = cv2.cvtColor(thin_image, cv2.COLOR_GRAY2RGB)
            self.display_image()


if __name__ == "__main__":
    app = QApplication([])
    window = ImageProcessingApp()
    window.show()
    app.exec()
