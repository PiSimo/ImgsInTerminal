# ImgsInTerminal

Display images in terminal with colored characters<br />
Requirements :<br />
      -Linux for the colored characters<br />
      -<a href="http://opencv.org/">OpenCV</a><br />
      -G++ compiler<br />
      -pkg-config<br />
 To Compile it :<br />
  <code>g++ textr.cc &#96;pkg-config --cflags --libs opencv&#96; -o textr</code><br />
 To run :<br />
  <code>./textr image-name.png</code><br />
  (NOTE:Use small images else you need to resize the font size of your terminal)

Example:<br/>
<img src="https://cloud.githubusercontent.com/assets/17238972/23415086/61ad1e40-fdde-11e6-8711-e7ffb6d2d075.png" />
