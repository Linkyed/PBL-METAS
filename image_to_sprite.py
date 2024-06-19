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
                lista.append(f"set_sprite_pixel_color({start}, 7, 0, 0);")
    return lista

# Step 1: Read the image
anf_img = Image.open('anfr.png').convert('L')  # Convert image to monochromatic (grayscale)
rans_img = Image.open('rans.png').convert('L')  # Convert image to monochromatic (grayscale)
erai_img = Image.open('erai.png').convert('L')  # Convert image to monochromatic (grayscale)

# Step 2: Convert the image to a numpy array
anf = np.array(anf_img)
rans = np.array(rans_img)
erai = np.array(erai_img)
#print(image_array)


start = 10000
lista_anf = return_pixel_codes(anf, 10000)
lista_rans = return_pixel_codes(rans, 10400)
lista_erai = return_pixel_codes(erai, 10800)

write_strings_to_file(lista_anf, 'anf_codes')
write_strings_to_file(lista_rans, 'rans_codes')
write_strings_to_file(lista_erai, 'erai_codes')

# Step 3: Convert the numpy array back to an image
#reduced_gray_image_128 = Image.fromarray(reduced_gray_array_128)


# Step 4: Save or display the image
#teste_image = Image.fromarray(novo_image)  # Save the image
#teste_image.show()
#teste_image.save("te.png")
