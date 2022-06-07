from PIL import Image 

f = open("qimage1.txt")
List = []
data = f.read()
lst = (data.split())
lst = list(map(int, lst))
lst = lst[::-1]
image = Image.open('image1.bmp')
image_rgb = image.convert('RGB')
pixels = image.load()
width, height = image.size

lst = bytes(lst)
# lst = lst[::-1]
img = Image.frombytes('RGB', (int(width), int(height)), lst)

img.show()

