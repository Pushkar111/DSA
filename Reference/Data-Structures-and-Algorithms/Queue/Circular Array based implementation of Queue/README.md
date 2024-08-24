# Performance and Limitations
### Performance:
    Let n be the number of elements in the queue, then :
| Operation | Complexity |
| --- | --- |
| Space Complexity (for n EnQueue operations) | O(n) |
| Time Complexity of EnQueue() | O(1) |
| Time Complexity of DeQueue() | O(1) |
| Time Complexity of printing the Queue | O(n) |

### Limitations:
    The maximum size of the queue must be defined as prior and cannot be changed.
    Trying to EnQueue a new element into a full queue causes an implementation-specific exception.
