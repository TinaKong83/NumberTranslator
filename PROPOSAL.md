# Proposal
For my final project, I am extending the Naive Bayes assignment. The project will allow the user to paint some digit from 0 to 9 
on an openFrameworks canvas. I will then process this digit as an image converted to pixels, using the Naive Bayes algorithm to classify
each user-inputted digit to the actual digit. Additionally, I plan to have a textbox where the user can enter one of a few preselected 
languages (e.g. English, Spanish, etc.). After the user-chosen language is processed, an image with the number translated in to that language 
and/or a pronunciation will appear on the scren. Additionally, the program will play an audio clip of the number. If the user inputs 
some unrecognizable number, I will display an error message image and prompt the user to retry.
There will also be options to clear the canvas.

If I have extra time, I want to see if I can erase only parts of what has been drawn so far (like an eraser tool), instead of only being 
able to clear the image entirely. Also, instead of having the user manually type in the language they want to translate the number into, 
I want to see if there is an openFrameworks feature that allows a dropdown menu (or ability to select an option). Also, I would like to
have the program be able to recognize 2 digit numbers (e.g. 10)

Some of the libraries I plan to use are ofSoundPlayer (to load and play the audio clips and background music), ofImage (for loading and 
processing the image), ofGraphics, ofxGUI, ofTrueTypeFontSettings (for displaying text in certain fonts). Some of the websites I plan
to use include:
- https://openframeworks.cc/documentation/
- https://openframeworks.cc///documentation/sound/ofSoundPlayer/
- https://openframeworks.cc/documentation/graphics/
- https://openframeworks.cc/documentation/graphics/ofTrueTypeFont/
- https://openframeworks.cc/documentation/ofxGui/ 