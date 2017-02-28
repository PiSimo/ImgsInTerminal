# ImgsInTerminal

Display images in terminal with colored characters<br7>
Requirements :<br />
      -Linux for the colored characters<br />
      -<a href="http://opencv.org/">OpenCV</a><br />
      -G++ compiler<br />
      -pkg-config<br />
 To Compile it :<br />
  <code>g++ textr.cc `pkg-config --cflags --libs opencv` -o textr</code><br />
 To run :<br />
  <code>./textr image-name.png</code><br />
  (NOTE:Use small images else you need to resize the font size of your terminal)
