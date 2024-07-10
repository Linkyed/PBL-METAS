from PIL import Image
import numpy as np

def write_strings_to_file(strings, filename):
    with open(filename, 'w') as file:
        for string in strings:
            file.write(string + '\n')

def return_pixel_codes(image, start):
    lista = []
    for line in image:
        for pixel in line:
            start += 1
            if (pixel[3] == 0):
                lista.append(f"set_sprite_pixel_color({start}, 6, 7, 7);")
            else:
                red = pixel[0] // 32
                green = pixel[1] // 32
                blue = pixel[1] // 32
                lista.append(f"set_sprite_pixel_color({start}, {red}, {green}, {blue});")
    return lista


def return_bg_blocks_codes(image):
    lista = []
    line_num = 0
    for line in image:
        column_num = 0
        for column in line:
            if (column[3] == 0):
                lista.append(f"set_background_block({column_num}, {line_num}, 6, 7, 7);")
            else:
                red = column[0] // 32
                green = column[1] // 32
                blue = column[1] // 32
                lista.append(f"set_background_block({column_num}, {line_num}, {red}, {green}, {blue});")
            column_num += 1
        line_num += 1
    return lista

img_sprite = Image.open('imgs/bomba.png')  # Convert image to monochromatic (grayscale)
img_bg_blocks = Image.open('imgs/pause_screen.png')

img_array_sprite = np.array(img_sprite)
img_array_bg_blocks = np.array(img_bg_blocks)


start = 400
lista_sprite = return_pixel_codes(img_array_sprite, start)
lista_bg_blocks = return_bg_blocks_codes(img_array_bg_blocks)

write_strings_to_file(lista_sprite, 'imgs/codes_txt/bomba_sprite')

