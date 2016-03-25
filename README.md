# HelloHook001
jump into hook - demo 001, I will re-write this about 10-20 time

follow this example to start with hook
http://diendan.congdongcviet.com/threads/t3407::hook-%E2%80%93-vi-du-nho-danh-cho-nguoi-mu.cpp

Hook là gì?

Trong Windows, khi chúng ta thực hiện các thao tác nhấp chuột, nhấn phím… thì hệ điều hành sẽ chuyển các sự kiện này thành các thông điệp (message) rồi đưa vào hàng đợi (queue) của hệ thống. Sau đó, các thông điệp được trao lại cho từng ứng dụng cụ thể để xử lý.

Hook là một kỹ thuật cho phép một hàm có thể chặn, theo dõi, xử lý, hoặc hủy bỏ các thông điệp trước khi chúng “mò” đến được ứng dụng.

Hai ví dụ thường gặp của Hook là ứng dụng soạn thảo văn bản tiếng Việt (Unikey, Vietkey…) và ứng dụng tra từ điển trực tiếp trên màn hình (Click’n’See, Lạc Việt MTD, English Study…). Chúng xử lý thông điệp từ bàn phím để đổi văn bản sang tiếng Việt, hoặc xử lý thông điệp từ con chuột để lấy văn vản dưới con trỏ. Chương trình KeyLogger chuyên ăn cắp mật khẩu cũng sử dụng kỹ thuật này.
