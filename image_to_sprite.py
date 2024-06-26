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
            if (pixel > 254):
                lista.append(f"set_sprite_pixel_color({start}, 7, 7, 7);")
            elif (pixel < 254 and pixel > 60):
                lista.append(f"set_sprite_pixel_color({start}, 3, 3, 3);")
            else:
                lista.append(f"set_sprite_pixel_color({start}, 0, 0, 0);")


    return lista

# Step 1: Read the image
img = Image.open('seta_mouse.png').convert('L')  # Convert image to monochromatic (grayscale)

# Step 2: Convert the image to a numpy array
img_array = np.array(img)
#print(image_array)


start = 10000
lista = return_pixel_codes(img_array, 10000)

write_strings_to_file(lista, 'seta_mouse_codes')

# Step 3: Convert the numpy array back to an image
#reduced_gray_image_128 = Image.fromarray(reduced_gray_array_128)


# Step 4: Save or display the image
#teste_image = Image.fromarray(novo_image)  # Save the image
#teste_image.show()
#teste_image.save("te.png")
