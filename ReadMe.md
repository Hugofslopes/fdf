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
<details>
    <summary>Parsing</summary>
    <ol>
        <li>Check if the number of arguments is correct</li>
        <li>Check if the second argument is a file, if its extension is .fdf and if it has the permissions to be read.</li>
        <li><b>create_map( )</b> is called to read each line of the input file and add each point of the map to a node in the linked list. To achieve this, I call <b>get_next_line( )</b>, and then assign each element to the node (x-axis, y-axis, and colors) using <b>atoi( )</b>. The <b>atoi( )</b> function was modified to handle input errors. Additionally, I check for any input errors when retrieving the colors and assign each color to its respective variable in the node.</li>
    </ol>
</details>

<details>
    <summary>Initialize</summary>
<b>init_mlx( )</b> is called to initialize all the necessary components to create an image, open a window and display the image on the window
    <ol>
        <li><b>Call mlx_new_window( )</b> to initialize the new window, which receives as parameters: a pointer to the mlx, the width, the height, and the name of the window</li>
        <li><b>Call mlx_new_image( )</b> to initialize the new image, which receives as parameters: a pointer to the mlx, the width and the height</li>
        <li><b>mlx_get_data_addr( )</b> to initialize the data needed for the image, which receives as parameters: a pointer to the image, the address of bits per pixel, the address of the size of the line, and the address for mlx endianness, which refers to the byte order used in the MiniLibX graphics library..</li>
    </ol>
</details>

<details>
    <summary>Prepare the image</summary>
    <ol>
        <li>Call <b>draw_map( )</b> to creat the image, puting pixel by pixel on it.</li>
        <li>Call <b>apply_zoom( )</b> to adjust the image to fit the size of the window.</li>
        <li>Call <b>isometric( )</b> to create the x and y points based on the x, y, and z values provided by the input. Multiplying by cos(30°) and sin(30°) scales these combined coordinates to the correct horizontal and vertical components of the projection. Subtracting the original z from the projected y adds depth, pushing points "up" or "down" based on their z value, which creates the illusion of height.</li>
        <p>
            <img src="https://github.com/user-attachments/assets/21f99c6e-7a0a-42ea-8602-b7fddf0b9a00"/>
        </p>
        <li>Call <b>center( )</b> To change the coordinates to position the image in the center of the window.</li>
    </ol>
</details>

<details>
    <summary>Draw the image</summary>
    <ol>
        <li>Call <b>draw_line( )</b> to draw each line of the image.</li>
        <li>First we define the <b>step</b> which will be the increment to each point</li>
        <p>
            <img src="https://github.com/user-attachments/assets/d8b031fd-d454-4933-b00c-1b8bdedf74ab"/>
        </p>
        <li>Define the increment for each step in the x and y directions. Dividing by step ensures the points are spaced evenly along the line.</li>
        <p>
            <img src="https://github.com/user-attachments/assets/17926604-a769-4495-9279-b6002d0b3fb4"/>
        </p>
        <li>Call <b>put_pixel( )</b> to add each pixel to the image.</li>
        <p>
            <img src="https://github.com/user-attachments/assets/70b30c52-d9a8-4ceb-a342-9b53ee8affbf"/>
        </p>
        <ol>
            <li><b>(*map)->mlx.adress:</b> This is a pointer to the beginning of the image data (pixel buffer).</li>
            <li><b>y * (*map)->mlx.line_length:</b> Calculates the offset in bytes to the start of the row y in the image. Line_length is the number of bytes in a single row (also called scanline).</li>
            <li><b>x * ((*map)->mlx.bits_per_pixel / 8):</b> Calculates the offset in bytes to the pixel x in the current row. Bits_per_pixel is the number of bits used to represent a single pixel. Dividing by 8 converts this to bytes per pixel.</li>
            <li><b>*(unsigned int *)pxl = color</b> Assigns the value of color to the pixel at the calculated address.</li>
        </ol>
    </ol>
</details>

<details>
    <summary>Display the image in the window and close the program</summary>
    <ol>
        <li>Call <b>mlx_put_image_to_window( )</b> to display the image that was created in the window, it receives the following parameters: a pointer to the mlx, a pointer to the window and a pointer to the image.</li>
        <li>Call <b>mlx_key_hook( )</b> to close the window, it receives the following parameters: a pointer to the window, a function that checks if the "Esc" key was pressed and a pointer to the structure that contains all the allocated memory to be freed.</li>
        <li>Call <b>mlx_hook( )</b> to close the window, it receives the following parameters: a pointer to the window; 17, which is the event code for the "Destroy Notify" event in MLX and X11; 0 which is the event mask (in this case, 0 because this event doesn't require an additional mask); a function that will call the function to free all the memory; and a pointer to the structure that contains all the allocated memory to be freed.</li>
        <li>Call <b>mlx_loop( )</b> To keep the window open until the "Esc" key is pressed or the close button is clicked with the mouse.</li>
    </ol>
</details>

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
As you can see from the example above, the functions that my program called the most were <b>get_next_line( )</b>, <b>create_map_list2( )</b> and <b>find_next_y( )</b>. The first two functions are directly related to my parsing process: <b>get_next_line( )</b> retrieves each line of the given map, while <b>create_map_list2( )</b> adds each value to the linked list. The last function, <b>find_next_y( )</b>, is called to determine the maximum y-coordinate for that line, allowing the loop to iterate until it reaches the end of the map. This is necessary because some maps have different numbers of columns.

## Improvements
<p>
    The parsing could be improved if i use one bi-dimensional array instead of an linked list. This will make the program execute big maps in a fastest way. There is one other improvement that can me made, that is reading the map for the last 'y' to the first and storing it in this way, to change the view from the object. No bonus made, for now . Its a possible improvement for the future.
</p>