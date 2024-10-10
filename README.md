#  VEDA 1기
## 2차 미니 프로젝트 (QTChatroom) ~10/28
### 요구 사항 및 제약 조건
* Qt를 이용한 고객관리 및 채팅 서버 및 클라이언트 구현
    * Qt 디자이너를 이용한 UI의 구성 : 로그인 화면 채팅 화면 등
    * UI와 데이터를 분리하여 MVC의 설계 기법을 적용
    * 클래스 간의 시그널과 슬롯을 이용해서 데이터를 전달

* 채팅 프로그램의 구현~~(BSD Socket~~ 혹은 **Qt Network** 모듈)
    * 채팅 프로토콜 설계와 채팅 서버와 채팅 클라이언트 프로그래밍
    * 채팅 관리의 구현 : 초대, 강제 탈퇴, 일 대 다 채팅, 첨부 파일 전송 등
    * 파일 전송 기능의 구현
    
* 타이머/멀티 스레드를 사용(~~PThread~~ 혹은 **QThread**)
    * 채팅 메시지 자동 저장 기능, 접속 로그 등 기록
    * 생성자/소비자 패턴을 적용하여 로그를 매체별 저장
    * Qt의 자료 구조(STL)을 이용해서 검색 등의 알고리즘을 사용
    
* 데이터베이스(Qt SQL 모듈)
    * Qt에서 제공하는 SQLite를 이용하여 데이터를 저장
    * DB 설계 및 데이터 관리 방법 습득
