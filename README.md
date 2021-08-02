# Survey

* 각종 결정 사항들 투표 함 (일주일 정도 투표하고 결정함)
  * [이전 투표들](https://github.com/kimjoy2002/crawl/blob/master/SURVEY.md)
  * 최근 투표
    * 김치죽 1.3.1 밸런싱 투표 (4.27~) 투표완료
      * 오토마톤-적절12표(54.5%) 사기7표(31.8%) 약함2표(9.1%) 너무약함1표(4.5%)
      * 하이브-적절10표(45.5%) 어려움6표(27.3%) 쉬움5표(22.7%) 너무어려움1표(4.5%)
      * 이머스테하-적절8표(44.4%) 약함5표(27.8%) 너무약함4표(22.2%) 사기1표(5.6%)
      * 포도-쎔12표(60%) 너무쎔4표(20%) 적절3표(15%) 약함1표(5%)
      * 레후딥-적절13표(56.5%) 사기7표(30.4%) 너무약함3표(13%)
    * 김치죽 1.3.1 기타 투표 (4.27~) 투표완료
      * 팔렌통가바딩-바딩통합16표(59.3%) 나가바딩사용6표(22.2%) 켄타바딩사용3표(11.1%) 팔렌통가바딩별도추가2표(7.4%)
      * 0.27리워크지니-재해석해서새종족9표(32.1%) 리워크지니따로추가8표(28.6%) 비크롤오니6표(21.4%) 트렁크지니로통합5표(17.9%)
      * 0.27아쉔자리-아쉔현황유지및개선21표(70%) 리워크아쉔자리로변경5표(16.7%) 둘다따로구현4표(13.3%)
      * 수정창-수정창유지14표(50%) 랜스로변경14표(50%)
      * 마법오염개편-찬성14표(51.9%) 반대13(48.1%)
      * 개발선호도
        * 잘안쓰이는종족직업신재해석및개선-22표(73.3%)
        * 새로운매커니즘활용한종족직업신-18표(60%)
        * 신규컨텐츠밸런싱-13표(43.3%)
        * 마법아티,미니볼트추가-13표(43.3%)
        * 기존삭제된종족직업신롤백-8표(26.7%)
      * 기타의견 - https://forms.gle/w3FC1BaHeAg2cEjGA
    * 김치죽 0.27 적용 투표 (8.03~8.20) https://forms.gle/xXoati7F9kYHXVH77
      
# Design goals

* 삭제보단 컨텐츠 추가를 중심으로 개발을 할 예정임
  * 컨텐츠 추가에 대해서는 밸런스적인 문제가 보여도 우선 추가를 목표로 함 (선추가 후밸런싱)

* 현재 시스템을 유지하는 선에서 옛날 컨텐츠 복구도 주요 목표 중 하나임

* 일부 개선이나 추가를 하다보면 찬반이 갈릴 수 있는데 이 경우 투표를 진행할 예정임
  * 일주일정도 투표나온 결과로 진행함
  
* 나머지는 부담없이 자유롭게 진행하자

# Dungeon Crawl Stone Soup Korea Fork

[Dungeon Crawl Stone Soup](https://github.com/crawl/crawl/)의 포크

돌죽 0.24버전을 베이스로 시작함. 목표는 위에 디자인 골을 참고

누구나 참여가능한 돌죽 포크를 지향함

* 기여 방법
  1. Pull requests를 통한 기여
     * 이 브랜치를 Fork를 따서 작업후 Pull requests 요청하기
     * 빌드가 실패하는게 아니면 왠만해선 허용합니다.
     
     
  2. 직접 참가하기
     * pull request가 아니라도 어느정도 코딩할줄아는 수준이시면 레포지터리 권한 다 드림
     * 이렇게 권한을 받으면 직접 push해도 상관없음
     
    
  3. 기획 혹은 버그 신고
     * 코딩을 할 줄 몰라도 위에 Issues 메뉴에서 아이디어 제공, 혹은 버그 제보로 참여가능
     

# How to Build
  * 원본영어 판은 [링크](https://github.com/kimjoy2002/crawl/blob/master/crawl-ref/INSTALL.txt)를 참조 
  * 한글 해석 [링크](https://gall.dcinside.com/board/view/?id=rlike&no=261405)
    * [링크](https://github.com/kimjoy2002/crawl/issues/18) <- 빌드시 문제 발생하면 참조하기

# Develop Guide
  * 직업 만들기 [영어원문](https://github.com/kimjoy2002/crawl/blob/master/crawl-ref/docs/develop/background_creation.txt) [한글번역](https://gall.dcinside.com/board/view/?id=rlike&no=96789)
  * 신 만들기 [영어원문](https://github.com/kimjoy2002/crawl/blob/master/crawl-ref/docs/develop/god_creation.txt) [한글번역](https://github.com/kimjoy2002/crawl/issues/116)
  * 몬스터만들기 [영어원문](https://github.com/kimjoy2002/crawl/blob/master/crawl-ref/docs/develop/monster_creation.txt)
  * 변이 만들기 [영어원문](https://github.com/kimjoy2002/crawl/blob/master/crawl-ref/docs/develop/mutation_creation.txt)
  * 종족 만들기 [영어원문](https://github.com/kimjoy2002/crawl/blob/master/crawl-ref/docs/develop/species_creation.md)
  * 마법 만들기 [한글원문](https://gall.dcinside.com/board/view/?id=rlike&no=318987)

# ChangeLog
  
  [Link](https://github.com/kimjoy2002/crawl/blob/master/CHANGELOG.md)
  
# Webtile (Test Server)

* 웹타일주소
  *  http://joy1999.codns.com:8081/
  * 3시간마다 자동 업데이트함. push버전을 바로바로 테스트하고싶으면 이걸 이용
  * 플레이용도보단 테스트용도기때문에 위자드모드 가능한 버전도 열어뒀음
  * 주의) 기본적으로 서버용 컴퓨터가 아니라서 느림. 플레이용이 아닌 테스트용도로만 사용하세요

# Download

* [![Build Status](http://joy1999.codns.com:8080/buildStatus/icon?job=crawl%2Fcrawl)](http://joy1999.codns.com:8080/job/crawl/job/crawl/)

* Last Release (kimchi-1.3.2)
  * https://github.com/kimjoy2002/crawl/releases/tag/kimchi-1.3.2

* 타일판 다운로드
  * http://joy1999.codns.com:8999/download/stone_soup-kimchi-trunk-tiles-win64.zip - 64비트
  * http://joy1999.codns.com:8999/download/stone_soup-kimchi-trunk-tiles-win32.zip - 32비트
  * 매일 밤 새벽3시 자동 업데이트

* 콘솔판 다운로드
  * http://joy1999.codns.com:8999/download/stone_soup-kimchi-trunk-win64.zip - 64비트
  * http://joy1999.codns.com:8999/download/stone_soup-kimchi-trunk-win32.zip - 32비트
  * 매일 밤 새벽3시 자동 업데이트
  
* 이전 다운로드 파일들
  * http://joy1999.codns.com:8999/download/crawl/
  * 매일 자동빌드된 파일들이 올라감 너무 오래되면 삭제
