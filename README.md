## TODO CLI

Create and list todo from command line

We would pass arguments when calling the command

1. todo **add** - would add whatever comes after the add keyword to the file
2. todo **list** - would list all todos in a file.
3. todo **remove** would remove a task with the same name that whatever you wrote after remove
4. todo **clean** would delete all tasks

#### Example

```console
todo add study pointers
```

This would add study pointers to a file

```console
todo list
```

This would list everything inside that file.

```console
todo delete study pointers
```

This would remove study pointes from the file.

```console
todo clean
```

Delete everything


### Json structure of the tasks

```json
  {
    "tasks": []
  }
```

### Using

Add the following in your .bashrc file:

```javascript
export PATH="path/to/your/executable:$PATH"
```

Make sure you have a json file called tasks.json in the same directory you put your executable file and it should have the same structure (just copy and paste the structure inside a tasks.json file). For exampel i have mine in the following dir:  

here is the path to tasks.json file
/home/danilo/Documents/todocli/tasks.json

Here is the executable path that i pu inside my .bashrc
/home/danilo/Documents/todocli/ 

# TODO

1. Fix the path for the tasks.json file
