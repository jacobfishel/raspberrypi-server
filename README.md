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





