/*==================================================================================================
                                      **RTE (Run-Time Environment)**
==================================================================================================*/
Chứa các ứng dụng phần mềm, bao gồm các chức năng dành riêng cho xe như điều khiển động cơ, phanh,
điều hòa không khí, v.v. Các ứng dụng này được thiết kế dựa trên các thành phần phần mềm (SWC -
Software Components).


/*==================================================================================================
                                      **RTE (Run-Time Environment)**
==================================================================================================*/
Là môi trường giao tiếp giữa Application Layer và các layer bên dưới. RTE đảm bảo các thành phần
phần mềm giao tiếp với nhau một cách độc lập, bất kể phần cứng.


/*==================================================================================================
                                      **BSW (Basic Software Layer)**
==================================================================================================*/
**System Services:** Cung cấp các dịch vụ hệ thống như quản lý bộ nhớ, quản lý thời gian.
**ECU Abstraction Layer:** Trừu tượng hóa phần cứng, cung cấp giao diện để truy cập phần cứng mà
không cần biết chi tiết cụ thể.
**MCAL (Microcontroller Abstraction Layer):** Cung cấp giao diện trừu tượng để truy cập vào các
thành phần vi điều khiển như I/O, ADC, CAN.