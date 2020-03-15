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
    "tasks": [
      "study pointers",
      "play video games",
      "watch netflix",
      "finish homework"
    ]
  }
```
