<p align="center">
    <img src="https://www.42porto.com/wp-content/uploads/2024/08/42-Porto-Horizontal.png"/>
</p>
<h1 align="center">Fdf</h1>
<p align="center">
    <img src="https://github.com/user-attachments/assets/fc63707e-31bb-4f51-9c68-25f85ea0d679"/>
</p>

## Summary
<p>
    <b>Fdf</b> is a project from 42 School that aims to teach how to draw an isometric representation of a given map. The program should read a map from a .fdf file, create an image representation with colors (if provided), and then display it in a window. For this project 42 gave us the mlx library, that is a simple graphics library. MLX uses X11 to create and manage the windows needed to display images.
</p>

## Code Phases
<p>    
    asdsad
</p>

## Code Setup
<p>    
    <b>Step 1:</b> Clone the repository
</p>

    git clone https://github.com/Hugofslopes/fdf.git    

<p>
    <b>Step 2:</b> Open the terminal on the repo folder and write
</p>

    make

<p>
    <b>Step 3:</b> Execute
 </p>

    ./fdf <map_name>

<p>
    <b>Step 4:</b> Close the windown and open new test.
    To creat a log file taht will check num,ber of calls for each funtion and the time that it took you shoud add the <b>-pg</b>, on my case i just aded that before gdb flag. Executing the program with this flag will genereat a gmon.out file. Then to generate the log file you just nee to run the folowing command:
</p>
    
    gprof <executable_name> gmon.out > log_file

this will generate the log file and will creat the log_file with the content from the log
## Improvements
<p>
    The parsing could be improved if i use one bi-dimensional array instead of an linked list. This will make the program execute big maps in a fastest way. There is one other improvement that can me made, that is reading the map for the last 'y' to the first and storing it in this way, to change the view from the object. No bonus made, for now . Its a possible improvement for the future.
</p>