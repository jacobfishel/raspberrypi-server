# raspberrypi-server

Goal:

    set up a server on my raspberry pi that will listen for a request to communicate, acknowledge it and sync. 

    communicate with this program from my other computer to the raspberry pi and have it echo all communication back to the pi. 


# Current task: 
    convert all the c code over to python 
    DONE

# Idea:
Make the raspberry pi the database. Do some object detection which will be the main project, but every time I run my camera and detect models, the code pushes these images and info about them to the pi. 
    # Sends image to the pi
        # The pi uses SQL commands to insert and SELECT from the database its storing 
    # Reasoning:
        I want practice with servers and databases which is why I am connecting to the pi via server and storing data in the database using MySQL



# Project architecture:
    [ Main PC (Client) ]
    |
    |   (TCP or HTTP requests, or even socket+json)
    |
    [ Raspberry Pi (server)]
        -Runs MySQL
        -Handles requests to log/query data

# Optional add-ons:
    - Main pc can have a GUI or CLI
    -Later throw a dashboard on top of the pi

# CheckList:
    - Train a model from scratch
        - Using the wider face dataset
    - Have the raspberry pi server to send data to
        - It will then query the data into and from the MySQL database on it.
    - Create a GUI local app to run the camera
        - Tkinter or PyQt (runs as a windowed desktop app)
            - Nice because no need for html/css just python

    # Maybes:
        - website + flask



ACTIVE TODO:
    - parse_wider.py: maybe just clean up the code a little bit
    - Build the training pipeline:
        - write a dataset class 
        - load annotations
        - apply transformations
        - write model
        - train model
        - save model
    - Test model
    - Loop back if errors
    - Then flask backent routes to serve the model
    - Frontend to call routes and display detection
    - Research what comes next. Probably building the model, or formatting the data more.

Progress:
    4.16.2025
        - planned out the strucure of the project
        - Created the file structure
        - Downloaded the dataset
        - Got the echo server running 
            - (will be modified and implemented later. This was mostly for practice)
    
    4.17.2025
        - Wrote the parse function for the annotation file
        - Did a lot of research on the way the annotation file should be formatted
            - tuple containing image file path and 2d array of bbox coords ("", [[]])

    4.18.2025
        - Finished testing the parse file function. It contains the correct numbers of jpg filenames and when I loop through all bounding boxes, they are in the file, so I'm content with this check. 




