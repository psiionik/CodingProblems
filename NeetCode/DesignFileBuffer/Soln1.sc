import java.io.FileOutputStream

object Solution1 {
    class BufferedFileWriter(f: java.io.File, buffer_size: Int) {
        val f_ref = f 
        val size = buffer_size
        val buf = Array.fill(size)(0.toByte)
        var buffer_index = 0

        def write(bytes: Array[Byte]): Int = {
            val bytes_to_write = bytes.length
            var bytes_written = 0

            while (bytes_written < bytes_to_write) {
                // Basically taking the min of the remaining in our buffer vs. remaining of bytes to write
                val amount_to_write = Math.min(size - buffer_index, bytes_to_write - bytes_written)
                System.arraycopy(bytes, bytes_written, buf, buffer_index, amount_to_write)

                buffer_index += amount_to_write
                bytes_written += amount_to_write

                if buffer_index == size
                then
                    flush()
                    buffer_index = 0
            }

            1
        }

        def flush(): Unit = {
            try 
                val fos = new FileOutputStream(f_ref)
                fos.write(buf.slice(0, buffer_index))
                println("Flushed buffer to file!")
            catch
                case _: Exception => {
                    println("Something went wrong when trying to flush buffer out to file!")
                }
        }
    }
}