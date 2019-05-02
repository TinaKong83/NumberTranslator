# Final Project
## Overview
In this project, I extended the Naive Bayes assignment. The user can use their mouse to draw a digit (0 to 9) onto a canvas and then translate it into 1 of 4 languages. There are options to hear the translation audio, and see a character/pronunciation

### Code Style
Written using Google C++ Style Guide (https://google.github.io/styleguide/cppguide.html)

## Demo
![image](https://user-images.githubusercontent.com/42946669/57054089-fe8b3000-6c57-11e9-8223-642b1cce493e.png)
After the user draws and submits a number, they can press 'C' to clear the image. After selecting a language, the user presses 'enter' to play an audio clip of the number in the selected language.

## Resources
I used ofSoundPlayer to load and play the translation sounds from mp3 files, ofImage to load pictures of the Chinese characters and convert the user drawing into GrayScale, ofLine for the drawing tool

## Problems Encountered and Future Improvements
I initially tried to load the Chinese characters using ofTrueTypeFont, but it was unable to recognize special unicode characters. Therefore, I decided to upload images of the characters instead
Currently, the program has a lower accuracy rate and only recognizes the number if it is drawn in the center of the canvas. A potential improvement would be enabling the program to recognize the digit at any location and any size.