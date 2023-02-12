// SPDX-License-Identifier: GPL-3.0

pragma solidity ^0.4.17;

contract Mycontract2 {
    
    // c
    // max of 17 different atrtributes of differnet data types.
    struct Employee {
        string _firstName;
        string _lastName;
        uint _id;
    }

    Employee[] public emps; 
    // just continuos storage of data.
    // uint[] public integerArray;

    // mapping -> dictionary in python or hash tables in Java. 
    // store key value pairs
    mapping(uint => Employee) public emp;

    // internal functions - functions which could only be used by our own smart contract
    // similar to private methods in other programming languages
    uint i = 0;
    // change to internal count
    function incrementCount() internal {
        i += 1;
    }

    // methods which could only be called by owner of the smart contract are marked with adress keyword
    // another data type which can only store wallet adresses.
    // modifier functions are the ones tht change behaviour of the functions or restrict actions of functions based on some norms/rules
    address owner;
    
    modifier onlyOwner {
        require(msg.sender == 0x5B38Da6a701c568545dCfcB03FcB875f56beddC4);
        _;
    }


    constructor () public {
        owner = msg.sender;
    }

    // external funciotns are the ones that cannot be called from the same smart contract But it can only be called from other smart contracts.
    // function myfunction() external view {
    //     // do eomthing
    // }

    function myfunction() external view {
        // myfunction(); // cannot be called/
        // con().someFunc();
    }

    // private functions are the most restrictive visibility type. The can only be called withint the same smart contract
    // diff b/w private and internal 
    // private functions can only be seen and called from the same contract
    // internal functions can be called from the same contract but also in hte contracts that inherit this smart contract.
    function randomFunc() private view {
        // does somehting
    }

    function randomFunc1() private view {
        randomFunc();
    }

    function addNewEmployee(string memory _firstName, string memory _lastName, uint id) public onlyOwner {
        emps.push(Employee(_firstName, _lastName, id));
        emp[i] = Employee(_firstName, _lastName, id);
        incrementCount();
    }

    function getEmpAtIndexFromArray(uint index) public view returns(Employee memory) {
        return emps[index];
    }

    function getEmpAtIndexFromMap(uint index) public view returns(Employee memory) {
        return emp[index];
    }
}

contract con {
    function someFunc() external view {
        // does something
        // Mycontract2().randomFunc();
    }
}