# libft
My own library in c

## Running Tests
![](https://pbs.twimg.com/media/EbHalBQXYAE1XwD.jpg:large)

To test your functions, you’ll need to copy the `tests` directory into the root of your project directory. Ensure all files in the root directory do **not** contain a `main` function.

### Directory Structure

Your directory should look like this:

```plaintext
project-root/
├── ft_func1.c
├── ft_func2.c
├── ...
└── tests/ # directory goes here
```

### Usage

To run test on a particular function, use the following command:

```bash
./tests/runtests.sh memmove
```
Replace `memmove` with the name of the function you want to test.


To test the entire library, use the following command:


```bash
./tests/runtests.sh all
```
