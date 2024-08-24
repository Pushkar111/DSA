# Performance & Limitations

### Performance
    Let n be the number of elements in the stack. The complexities of stack operations with this
representation can be given as:
| Operation | Complexity |
| --- | --- |
| Space Complexity (for n push operations) | O(n) |
| Time Complexity of Push Operation | O(1) |
| Time Complexity of Pop Operation | O(1) |
| Time Complexity of Peek Operation | O(1) |
| Time Complexity of printing the Stack | O(n) |

### Limitations
    The maximum size of the stack must first be defined and it cannot be changed.
    Trying to push a new element into a full stack causes an implementation-specific exception.
