object Solution1 {

    /**
     * Your MyCircularQueue object will be instantiated and called as such:
     * val obj = new MyCircularQueue(k)
     * val param_1 = obj.enQueue(value)
     * val param_2 = obj.deQueue()
     * val param_3 = obj.Front()
     * val param_4 = obj.Rear()
     * val param_5 = obj.isEmpty()
     * val param_6 = obj.isFull()
     */

    class MyCircularQueue(_k: Int) {
        val _size = _k
        val _mem = Array.fill(_size)(0)
        var front_pointer = 0
        var count = 0

        def enQueue(value: Int): Boolean = {
            if isFull()
            then
                false 
            else
                _mem(java.lang.Math.floorMod(front_pointer + count, _size)) = value
                count += 1
                true
        }

        def deQueue(): Boolean = {
            if isEmpty()
            then
                false            
            else
                front_pointer = java.lang.Math.floorMod((front_pointer + 1), _size)
                count -= 1
                true
        }

        def Front(): Int = {
            if isEmpty()
            then
                -1    
            else
                _mem(front_pointer)
        }

        def Rear(): Int = {
            if isEmpty()
            then
                -1    
            else
                _mem(java.lang.Math.floorMod(front_pointer + count - 1, _size))
        }

        def isEmpty(): Boolean = {
            count == 0
        }

        def isFull(): Boolean = {
            count == _size
        }
    }
}