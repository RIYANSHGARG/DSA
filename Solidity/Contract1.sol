// SPDX-License-Identifier: GPL-3.0

pragma solidity ^0.4.17;

contract Contract1 {

    string public x="value";

    function get() public view returns(string memory) {
        return x;        
    }
    
    function set(string memory _x) public {
        x=_x;
    }
}