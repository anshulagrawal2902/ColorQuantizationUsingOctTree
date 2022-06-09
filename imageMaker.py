from PIL import Image 

f = open("MARBLES.txt")
List = []
data = f.read()
lst = (data.split())
lst = list(map(int, lst))
image = Image.open('MARBLES.bmp')
image_rgb = image.convert('RGB')
pixels = image.load()
width, height = image.size
lst = bytes(lst)
img = Image.frombytes('RGB', (int(width), int(height)), lst)
img.show()

