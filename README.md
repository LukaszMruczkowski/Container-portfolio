# Optical Device Collection

This project is a C++ program that demonstrates the implementation of a collection of optical devices using a linked list. It includes a class hierarchy representing different types of optical devices, such as cameras, and a template class for managing a collection of these devices.

## Optical Device Class Hierarchy

The optical device class hierarchy consists of two classes: `optical_device` and `camera`. Here is a brief overview of each class:

### `optical_device` Class

The `optical_device` class represents a generic optical device. It contains the following member variables and functions:

- `zoom`: A double value representing the zoom level of the device.
- `weight`: An integer value representing the weight of the device.
- `next`: A pointer to the next optical device in the linked list.
- `zoom_getter()`: A getter function for retrieving the zoom level.
- `weight_getter()`: A getter function for retrieving the weight.
- `zoom_setter(double z)`: A setter function for setting the zoom level.
- `weight_setter(int w)`: A setter function for setting the weight.
- `print()`: A function that prints the attributes of the optical device.

### `camera` Class

The `camera` class is a derived class from `optical_device` and represents a specific type of optical device, a camera. It adds the following member variables and functions:

- `battery_life`: An integer value representing the battery life of the camera.
- `video_format`: A string representing the video format supported by the camera.
- `battery_life_getter()`: A getter function for retrieving the battery life.
- `format_getter()`: A getter function for retrieving the video format.
- `battery_life_setter(int b_life)`: A setter function for setting the battery life.
- `format_setter(string format)`: A setter function for setting the video format.
- `print()`: An overridden function that prints the attributes of the camera.

## Unique Collection Template Class

The project also includes a template class called `unique_collection`, which represents a container for storing unique instances of optical devices. The `unique_collection` class has the following features:

- It uses a linked list implementation to store the devices.
- The `insert()` function allows adding new devices to the collection.
- The `remove()` function allows removing devices from the collection.
- The `show()` function prints the attributes of all the devices in the collection.

## Main Function

The `main()` function demonstrates the usage of the `unique_collection` class with instances of the `camera` class. It performs the following actions:

- Creates an instance of `unique_collection<camera>`.
- Creates three instances of the `camera` class (`A1`, `A2`, and `A3`).
- Inserts the cameras into the collection.
- Prints the collection before and after deleting a camera.
- Deletes the collection.

## Usage

To run the program, compile it using a C++ compiler and execute the resulting binary. The program will create a collection of cameras, insert some cameras, remove one camera, and display the contents before and after deletion.

Please note that this program is a simplified example for demonstration purposes and may not represent a fully functional optical device collection system. It serves as a starting point for further development and customization according to specific requirements.
