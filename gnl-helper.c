//1) check if leftover_buf has value, if yes, go to 2) else got to 4)
//2) check if a new line is found in leftover_buf, if found, go to 3) else go to 4)
//3) return that new line and store the leftover_buf and return to 1)

//4) If no new line or no leftover, read for more data into read_buf
//   If read returns > 0, recombine into leftover_buf, if read returns 0, go to 5
//5) Read returned 0, EOF reached, check if current leftover_buf contains '\n' 
//   and return that, else check subject

//BONUS
//change leftover_buf into char *leftover_buf[FD]
//where #define FD 1024

//NOTE
//Control it by the bytes read and not by NULL terminators

#define BUFFER 42
#define FD 1024

typedef struct s_gnl_state {
    char *buf;
    int buf_bytes;//to change to size_t
    int initialized;
} t_gnl_state;

static t_gnl_state buf_store;
//ssize_t read(int fd, void buf[.count], size_t count);
//change return type to ssize_t
int *ft_read(int fd)
{
    char *new_buf;
    int read_bytes;

    new_buf = (char *)malloc(BUFFER + 1);
    if (!new_buf)
        return ('\0');//to change to NULL
    read_bytes = read(fd, new_buf, BUFFER);
    if (read_bytes > 0)
    {
        ft_store_buffer(fd, read_bytes, new_buf);
        free(new_buf);
    }
    return (read_bytes);
}

void ft_store_buffer(int fd, int read_bytes, char *new_buf)
{
    int index;//change to size_t
    char *temp_buf;

    index = 0;
    if (buf_store.buf_bytes == 0)
    {
        buf_store.buf = (char *)malloc(read_bytes);
        if (!buf_store.buf)
            buf_store.buf = '\0';//change to NULL
        else
            while (index < read_bytes)
            {
                buf_store.buf[index] = new_buf[index];
                index++;
            }
    }
    else
        {
            temp_buf = ft_strjoin(new_buf, read_bytes, buf_store.buf, buf_store.buf_bytes);
            free(buf_store.buf);
            buf_store.buf = ft_substring(temp_buf, 0, buf_store.buf_bytes + read_bytes);
            free(temp_buf);
        }
    buf_store.buf_bytes += read_bytes;
}

char *ft_strjoin(char *src, int src_byte, char *dest, int dest_byte)
{
    char *temp_buf;
    int index;//change to size_t

    temp_buf = (char *)malloc(src_byte + dest_byte);
    if (!temp_buf)
        return ('\0');//To change to NULL
    index = 0;
    while(index < dest_byte)
    {
        temp_buf[index] = dest[index];
        index++;
    }
    while(index < dest_byte + src_byte)
    {
        temp_buf[index] = src[index];
        index++;
    }
    return (temp_buf);
}

char *ft_substring(char *src, int start, int bytes)
{
    int index;
    char *temp_buf;

    temp_buf = (char *)malloc(bytes);
    if (!temp_buf)
        return ('\0');//change to NULL
    index = 0;
    while (index < bytes)
    {
        temp_buf[index] = src[start + index];
        index++;
    }
    return (temp_buf);
}

char *ft_get_line()
{
    int index;
    char *new_line;
    char *temp_buf;

    index = 0;
    while (index < buf_store.buf_bytes)
    {
        if (buf_store.buf[index] == '\n')
            break;
        index++;
    }
    new_line = ft_substring(buf_store.buf, 0, index);
    buf_store.buf_bytes -= index;
    temp_buf = ft_substring(buf_store.buf, index, buf_store.buf_bytes);
    free(buf_store.buf);
    buf_store.buf = ft_substring(temp_buf, 0, buf_store.buf_bytes);
    free(temp_buf);
    return (new_line);
}
