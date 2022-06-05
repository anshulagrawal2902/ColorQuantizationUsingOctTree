from PIL import Image 

f = open("image3.txt")
List = []
data = f.read()
lst = (data.split())
lst = list(map(int, lst))

image = Image.open('image3.bmp')
image_rgb = image.convert('RGB')
pixels = image.load()
width, height = image.size

lst = bytes(lst)
lst = lst[::-1]
img = Image.frombytes('RGB', (int(width), int(height)), lst)

img.show()

