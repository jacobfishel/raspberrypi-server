
#Function to test that the number of images match in the array and in the file and making sure all the file paths have a correct file path
def test_num_of_images(filepath, parsed_data_arr):
  with open(filepath, 'r') as f:
    data = f.readlines()
    num_images_file = 0
    num_images_arr = len(parsed_data_arr)

    if data is None:
      return f"{filepath} is empty"

    for line in data:
      if 'jpg' in line:
        num_images_file = num_images_file + 1
  print(f"Total images in file: {num_images_file}")
  print(f"Total images in arr: {num_images_arr}")

  return num_images_file == num_images_arr


#function loops through annotated data and checks for:
  # if image is in file
  # if bbox is in file
def test_data_in_file(file_data, parsed_data):
  for dict in parsed_data:

    if dict['filename'].replace("data/WIDER/WIDER_train/images/", "")+'\n' not in file_data:
      print(f"Filename not found in file filename: {dict['filename']}")
      print(f"Matching Bbox: {" ".join(map(str, bbox))+' \n'}")
      
      return False, dict['filename']
    # print(f"dict[filename] = {dict['filename']}")
    # print(f"dict[bboxes] = {dict['bboxes']}")
    for bbox in dict['bboxes']:
      if " ".join(map(str, bbox))+' \n' not in file_data:
        print(f"Bbox not found in file: {" ".join(map(str, bbox))+' \n'}")
        print(f"Matching filename: {dict['filename']}")
        return False, dict['bboxes']
      # print(f"bbox: {bbox}")
  return True