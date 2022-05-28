from PIL import Image 
from colour import Color

file1 = open("RGB_vals", "w")
image = Image.open('image1.bmp')
image_rgb = image.convert('RGB')

pixels = image.load()
width, height = image.size


for j in range(height):
        for i in range(width):
            r, g, b = image_rgb.getpixel((i, j))
            string =  str(r) + " " + str(g) + " " + str(b) + " ";
            file1.write(string)