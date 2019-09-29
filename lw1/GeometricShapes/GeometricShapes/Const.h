#pragma once
#include <string>

const int POWER_NUMBER = 2;
const int MULTIPLICATION_FACTOR = 2;
const int ROUNDING_FACTOR = 3;

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;
const int ANTIALIASING_LEVEL = 8;
const std::string WINDOW_NAME = "Shapes";

const std::string ERROR_FILE_NOT_EXIST = "This file does not exist";
const std::string ERROR_NOT_ENOUGH_ARGUMENTS = "The number of arguments does not match the task condition\n"
											   "Input should look: GeometricShapes.exe <input file>\n";
const std::string ERROR_EMPTY_INPUT = "You have not created a shape";
const std::string INPUT_FILE_NAME = "input.txt";

const std::string FIGURE_RECTANGLE = "RECTANGLE";
const std::string FIGURE_TRIANGLE = "TRIANGLE";
const std::string FIGURE_CIRCLE = "CIRCLE";
const std::string FIGURE_UNKNOWN = "Unknown figure\n";

const std::string PERIMETER_SHAPE = "Perimeter = ";
const std::string AREA_SHAPE = "Area = ";
const std::string SPACE = " ";
const std::string COLON = ": ";
const std::string SEMICOLON = "; ";
