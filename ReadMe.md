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
    <b>Step 4:</b> Tests<br> 
    To create a log file that will track the number of calls for each function and the time it took, you should add the `-pg` flag. In my case, I just added that flag before the `gdb` flag. Executing the program with this flag will generate a `gmon.out` file. Then, to generate the log file, you just need to run the following command:
</p>
    
    gprof <executable_name> gmon.out > log_file
<p align="center">
    <img src="https://github.com/user-attachments/assets/b594a1e4-66ea-4450-97a6-2c6ed24fca64"/>
</p>
As you can see from the example above, the functions that my program called the most were <b>get_next_line( )</b>, <b>create_map_list2( )</b>, and <b>find_next_y( )</b>. The first two functions are directly related to my parsing process: <b>get_next_line( )</b> retrieves each line of the given map, while <b>create_map_list2( )</b> adds each value to the linked list. The last function, <b>find_next_y( )</b>, is called to determine the maximum y-coordinate for that line, allowing the loop to iterate until it reaches the end of the map. This is necessary because some maps have different numbers of columns.

## Improvements
<p>
    The parsing could be improved if i use one bi-dimensional array instead of an linked list. This will make the program execute big maps in a fastest way. There is one other improvement that can me made, that is reading the map for the last 'y' to the first and storing it in this way, to change the view from the object. No bonus made, for now . Its a possible improvement for the future.
</p>