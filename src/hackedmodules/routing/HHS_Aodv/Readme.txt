Học viên cao học: Hoàng Hồng Sơn - Trường Đại học Công nghệ
Giao thức bảo mật ids-AODV
---------------------------------------------------------------------------------
Ý tưởng:  
Tấn công blackhole sẽ sinh ra gói tin giả mạo RREP với số Seq# lớn nhất có thể. 
Khi đó tất cả các gói tin RREP khác đều không được chọn do có Seq# nhỏ hơn. 
Giao thức ids-AODV [7]giả sử rằng RREP có số Seq#  lớn  thứ 2  mới  là  gói  tin  RREP  thực  
vì  thế nó  sẽ bỏ qua  gói  tin  có  số Seq#  lớn  nhất  do  tấn  công blackhole giả mạo.
[7]: Performance analysis of ad-hoc networks under black hole attacks (Semih Dokurer)
----------------------------------------------------------------------------------
Thực hiện:
Để thực hiện được ý tưởng này, giao thức idsAODV xây dựng cơ chế lưu trữ gói tin RREP với mục đích 
lấy gói tin có số Seq# lớn thứ 2.
Trong RREP function:
+ nếu gói tin RREP đã được lưu lại từ trước đó cho cùng 1 địa chỉ đích thì thực hiện function RREP như thông thường
+ nếu gói tin RREP chưa từng được lưu lại thì chèn (insert) gói tin vào bộ nhớ đệm, giải phóng gói tin đồng thời thoát khỏi hàm.
