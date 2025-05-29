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
        var back_pointer = 0
        var is_full = false

        def enQueue(value: Int): Boolean = {
            if isFull()
            then
                false 
            else
                _mem(back_pointer) = value
                back_pointer = java.lang.Math.floorMod((back_pointer + 1), _size)
                if front_pointer == back_pointer
                then
                    is_full = true
                true
        }

        def deQueue(): Boolean = {
            if isEmpty()
            then
                false            
            else
                front_pointer = java.lang.Math.floorMod((front_pointer + 1), _size)
                if front_pointer == back_pointer
                then
                    is_full = false

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
                _mem(java.lang.Math.floorMod((back_pointer - 1), _size))
        }

        def isEmpty(): Boolean = {
            front_pointer == back_pointer && !is_full
        }

        def isFull(): Boolean = {
            front_pointer == back_pointer && is_full
        }
    }
}