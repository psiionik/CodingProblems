"""
Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext

The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty
second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. 
For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", 
and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path 
to a file in the abstracted file system. If there is no file in the system, return 0.
"""

"""
Solution 1, Use string splitting to split by '\n' since this means that it represents another node. Going to represent the tree
as a tree. Going to traverse through every single node recursively and concatenate the length of the strings as it goes down. To tell
which nodes are children of which, use string splitting to look at the number of "\t" in the string after splitting by "\n". Keep track
of the length from each leaf node and then return the max length. Start with base case from the leaves. Return the max of the length from
the recursion plus the length of the current node. 
"""

def max_absolute_path_sol1(s):
    pass

"""
Solution 2, First parse the string representing the file system and then get the absolute longest path to a file. Ideally, each
directory will be a dictionary where each key with a value as a dictionary represents another folder and a key with a value of True
represents an actual file. Can first split the string by the newline characters. This means that each element in the array is either
a file or a directory. Then create an empty directory to represent the parsed system and traverse the file system on each entry.
Keep track of the last path we've seen so far in current_path since we may need to return to some level in that path depending on
the number of tabs. Once we are at a correct place to put down the new dictionary or file, we check the name for a "." and set the
current value to either True or {} (if it is a directory). After constructing the dictionary, we can write a recursive function that
takes the current root and returns the longest one. Since we want a specific file, we discard any paths that do not have a "." in them.
If there are no paths starting from this root, we can just return the empty string "". Runtime is O(n) since we iterate over the input
string twice to build the file system. Worst case, we go through the string to compute the longest path.
"""

def build_path(s):
    fs = {}
    files = s.split('\n')
    current_path = []
    for f in files:
        indentation = 0
        while '\t' in f[:2]:
            indentation += 1
            f = f[1:]
        current_node = fs
        for subdir in current_path[:indentation]:
            current_node = current_node[subdir]
        
        if '.'  in f:
            current_node[f] =  True
        else:
            current_node[f] = {}

        current_path = current_path[:indentation]
        current_path.append(f)

    return fs

def longest_path(root):
    paths = []
    for key, node in root.items():
        if node == True:
            paths.append(key)
        else:
            paths.append(key + '/' + longest_path(node))

    paths = [path for path in paths if '.' in path]
    if paths:
        return max(paths, key=lambda path: len(path))
    else:
        return ''

def max_absolute_path_sol2(s):
    return len(longest_path(build_path(s)))

def main():
    print(max_absolute_path_sol2('dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext'))

main()