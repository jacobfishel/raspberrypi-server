# File to parse the wider dataset into the proper format to train data

# --------------- CODE ------------- #
# open the annotations file and modify data 
train_annotations_path = 'data/WIDER/annotations/wider_face_train_bbx_gt.txt'
train_images_folder_path = 'data/WIDER/WIDER_train/images/'
final_data_arr = []


with open(train_annotations_path, 'r') as f:
  data = f.readlines()


  img_path = None #jpg
  bbox_coords = [] #1, 2, 3, 4, 5, 6, 7, 78, 
  for i, line in enumerate(data):
    
    # If the line has 'jpg' its img path and parse each line until another jpg line
    if 'jpg' not in line:
      bbox_coords.append([line.strip()])
      continue
    else:
      #if img_path is not none, we are seeing jpg again:
        #push all info and reset values
      if img_path is not None:
        #Delete the num of bboxes from the coords (useless)
        del(bbox_coords[0])
        final_data_arr.append((img_path, bbox_coords))
        bbox_coords = []

      img_path = train_images_folder_path + line.strip()

  #Once we reach the end, push the final pieces of data
  del(bbox_coords[0])
  final_data_arr.append((img_path, bbox_coords))


print(final_data_arr[-1])

#Function to test that the number of images match in the array and in the file and making sure all the file paths have a correct file path
# def test_num_of_images():
#   pass
